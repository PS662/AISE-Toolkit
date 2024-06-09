#Q2
library(lpSolveAPI)

lprec <- make.lp(5, 6) # 6 variables and 5 constraints

lp.control(lprec, sense= "minimize") #  can change sense to  "maximize/minimize"

set.objfn(lprec, c(35, 62, 65, 28, 36, 32)) # set objective function

# set constraints
set.row(lprec, 1, rep(1,3), indices = c(1:3))
set.row(lprec, 2, rep(1,3), indices = c(4:6))
set.row(lprec, 3,rep(1,2), indices =c(1,4))
set.row(lprec, 4,rep(1,2), indices =c(2,5))
set.row(lprec, 5,rep(1,2), indices =c(3,6))

set.rhs(lprec, c(30, 20, 20, 18, 5))


set.constr.type(lprec, c("<=",	"<=", ">=", ">=",	">="))

set.type(lprec, c(1:6),"real")

set.bounds(lprec, lower = rep(0, 6), upper = rep(Inf, 6))

# write.lp(lprec, filename="test.lp")  Use write.lp to print out larger LPs. 
#  It produces a text file, which you can examine with any text editor.


solve(lprec) # http://lpsolve.sourceforge.net/5.5/solve.htm

objvalue<-get.objective(lprec)
objvalue
solution<-get.variables(lprec)
solution
lprec


#Q3
library(lpSolveAPI)

lprec <- make.lp(0, 6)

lp.control(lprec, sense= "maximize")  

set.objfn(lprec, c(0, 0, 0, 0, 0, 1))

add.constraint(lprec, c(-10, 0, 0, 0, 0, 1), "<=", 0)

add.constraint(lprec, c(-20, -20, 0, 0, 0, 1), "<=", 0)

add.constraint(lprec, c(-10, -10, -10, 0, 0, 1), "<=", 0)

add.constraint(lprec, c(0, 0, 0, 0, 0, 1), "<=", 0)

add.constraint(lprec, c(10, 10, 10, 10, 0, 1), "<=", 0)

add.constraint(lprec, c(1,1,1,1,1,0), "=", 1)

set.bounds(lprec, lower = c(0, 0, 0, 0, 0, -Inf))

RowNames <- c("Row1", "Row2", "Row3","Row4", "Row5", "Row6")

ColNames <- c("x1", "x2", "x3", "x4", "x5", "v")

dimnames(lprec) <- list(RowNames, ColNames)

lprec

solve(lprec) # http://lpsolve.sourceforge.net/5.5/solve.htm

get.objective(lprec)

get.variables(lprec)

get.constraints(lprec)

