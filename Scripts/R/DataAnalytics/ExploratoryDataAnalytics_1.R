#T1
#Loading data
forest_data = as.matrix(read.table("Fires_2021.txt"))

#selecting sampled data
sampled_forest_data = forest_data[sample(1:517,300), c(1:9)]

hist(sampled_forest_data[,1])

hist(sampled_forest_data[,2])
plot(x = sampled_forest_data[,1], y = sampled_forest_data[,2],
     xlab = "FFMC",
     ylab = "DMC",
     xlim = c(0, 100),
     ylim = c(0, 300),       
     main = "FFMC vs DMC"
)

hist(sampled_forest_data[,3])
plot(x = sampled_forest_data[,1], y = sampled_forest_data[,3],
     xlab = "FFMC",
     ylab = "DC",
     xlim = c(0, 100),
     ylim = c(0, 960),       
     main = "FFMC vs DC"
)

hist(sampled_forest_data[,4])
plot(x = sampled_forest_data[,1], y = sampled_forest_data[,4],
     xlab = "FFMC",
     ylab = "ISI",
     xlim = c(0, 100),
     ylim = c(0, 60),       
     main = "FFMC vs ISI"
)

hist(sampled_forest_data[,5])
plot(x = sampled_forest_data[,1], y = sampled_forest_data[,5],
     xlab = "FFMC",
     ylab = "Temp",
     xlim = c(0, 100),
     ylim = c(0, 50),       
     main = "FFMC vs Temp"
)

hist(sampled_forest_data[,6])
plot(x = sampled_forest_data[,1], y = sampled_forest_data[,6],
     xlab = "FFMC",
     ylab = "Humidity",
     xlim = c(0, 100),
     ylim = c(0, 100),       
     main = "FFMC vs Humidity"
)

hist(sampled_forest_data[,7])
plot(x = sampled_forest_data[,1], y = sampled_forest_data[,7],
     xlab = "FFMC",
     ylab = "wind",
     xlim = c(0, 100),
     ylim = c(0, 10),       
     main = "FFMC vs wind"
)

hist(sampled_forest_data[,8])
plot(x = sampled_forest_data[,1], y = sampled_forest_data[,8],
     xlab = "FFMC",
     ylab = "Rain",
     xlim = c(0, 100),
     ylim = c(0, 10),       
     main = "FFMC vs Rain"
)

hist(sampled_forest_data[,9])
plot(x = sampled_forest_data[,1], y = sampled_forest_data[,9],
     xlab = "FFMC",
     ylab = "Area",
     xlim = c(0, 100),
     ylim = c(0, 1150),       
     main = "FFMC vs Burned Area"
)

#T2
#selecting 4 variables
transformed_data <- as.matrix(c(sampled_forest_data[,2]))
transformed_data <- cbind(transformed_data, sampled_forest_data[,5], sampled_forest_data[,6], 
                          sampled_forest_data[,7], sampled_forest_data[,1])
#Checking transformed data
head(transformed_data)

#Standardization as all selected vars follow Gaussian dist
transformed_data[,1] <- (transformed_data[,1]-mean(transformed_data[,1]))/sd(transformed_data[,1])
transformed_data[,2] <- (transformed_data[,2]-mean(transformed_data[,2]))/sd(transformed_data[,2])
transformed_data[,3] <- (transformed_data[,3]-mean(transformed_data[,3]))/sd(transformed_data[,3])
transformed_data[,4] <- (transformed_data[,4]-mean(transformed_data[,4]))/sd(transformed_data[,4])

transformed_data[,5] <- (transformed_data[,5]-min(transformed_data[,5]))/(max(transformed_data[,5])-min(transformed_data[,5]))
#Checking data after transformations
head(transformed_data)
#saving data
write.table(transformed_data,"prateek-transformed.txt",)

#T3
source("AggWaFit718.R")
#weighted AM
wam <- fit.QAM(transformed_data,output.1="transformed_data_WAM.txt",stats.1="transformed_data_WAM_stats.txt") 

#weighted power mean with p = 0.5
pam05 <- fit.QAM(transformed_data,output.1="transformed_data_PM_05.txt",stats.1="transformed_data_PM_05_stats.txt", 
        g=PM05,g.inv = invPM05)

#weighted power mean with p = 2
pam2 <- fit.QAM(transformed_data,output.1="transformed_data_PM_2.txt",stats.1="transformed_data_PM_2_stats.txt", 
        g=QM,g.inv = invQM) 

chq <- fit.choquet(transformed_data, output.1="transformed_data_chq.txt",stats.1="transformed_data_chq_stats.txt",)

#T4
test_data = t(as.matrix(c(95.9, 158, 633.6, 11.3, 27.5, 29, 4.5, 0.0, 43.42)))

#pre-processing as T2
transformed_data2 <- as.matrix(c(sampled_forest_data[,2]))
transformed_data2 <- cbind(transformed_data2, sampled_forest_data[,5], sampled_forest_data[,6], 
                          sampled_forest_data[,7], sampled_forest_data[,1])

test_data_trans <- as.matrix(c(test_data[,2]))
test_data_trans <- cbind(test_data_trans, test_data[,5], test_data[,6], 
                   test_data[,7], test_data[,1])

test_data_trans[,1] <- (test_data_trans[,1]-mean(transformed_data2[,1]))/sd(transformed_data2[,1])
test_data_trans[,2] <- (test_data_trans[,2]-mean(transformed_data2[,2]))/sd(transformed_data2[,2])
test_data_trans[,3] <- (test_data_trans[,3]-mean(transformed_data2[,3]))/sd(transformed_data2[,3])
test_data_trans[,4] <- (test_data_trans[,4]-mean(transformed_data2[,4]))/sd(transformed_data2[,4])
test_data_trans[,5] <- (test_data_trans[,5]-min(transformed_data2[,5]))/(max(transformed_data2[,5]) - min(transformed_data2[,5]))

test_data_trans <- rbind(transformed_data, test_data_trans)

pam2 <- fit.QAM(test_data_trans,output.1="test_data.txt",stats.1="test_data_stats.txt", 
                g=QM,g.inv = invQM) 
op = as.matrix(read.table("test_data.txt"))
predicted_val <- op[301,][6]

#reversing transform for predicted value
predicted_val <- (predicted_val * (max(transformed_data2[,5]) - min(transformed_data2[,5]))) + min(transformed_data2[,5])
print(predicted_val)
#T5
relation <- lm(transformed_data[,c(5)] ~ transformed_data[,c(1)] + 
                 transformed_data[,c(2)] + transformed_data[,c(3)] + transformed_data[,c(4)])
summary(relation)

actual_values = transformed_data[,5]

tmp_data = transformed_data[,c(1)] + transformed_data[,c(2)] + transformed_data[,c(3)] + transformed_data[,c(4)]
tmp_data = data.frame(tmp_data)
lm_predicted_vals  = predict.lm(relation, tmp_data)

plot(lm_predicted_vals,
     actual_values,
     xlab = "Predicted Values linear regression",
     ylab = "Observed Values")
best_model_predicted_vals <- op[1:300,5]
plot(best_model_predicted_vals,
     actual_values,
     xlab = "Predicted Values power mean",
     ylab = "Observed Values")


