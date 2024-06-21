#include <gtest/gtest.h>
#include "base_object.hpp"
#include <thread>
#include <vector>

class ExampleDerived : public BaseObject<ExampleDerived> {};

TEST(BaseObjectTest, SingletonInstanceTest) {
    auto instance1 = ExampleDerived::GetInstance();
    auto instance2 = ExampleDerived::GetInstance();

    // Test that the instances are the same (Singleton check)
    EXPECT_EQ(instance1.get(), instance2.get()); // Compare raw pointers managed by shared_ptr
}

TEST(BaseObjectTest, NewInstanceTest) {
    auto instance1 = ExampleDerived::GetInstance();
    auto newInstance = ExampleDerived::GetInstance(true); // Explicitly create a new instance

    // Test that newInstance is different from the singleton instance
    EXPECT_NE(instance1.get(), newInstance.get()); // Ensure they are different instances
}

TEST(BaseObjectTest, ThreadSafeSingletonTest) {
    const int thread_count = 10;
    std::vector<std::thread> threads;
    std::vector<std::shared_ptr<ExampleDerived>> instances(thread_count);

    // Create multiple threads to access the singleton instance
    for (int i = 0; i < thread_count; ++i) {
        threads.emplace_back([&instances, i]() {
            instances[i] = ExampleDerived::GetInstance();
        });
    }

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    // Check that all instances are the same
    for (int i = 1; i < thread_count; ++i) {
        EXPECT_EQ(instances[0].get(), instances[i].get());
    }
}

#ifdef USE_MEYERS_SINGLETON
TEST(BaseObjectTest, MeyersSingletonInstanceTest) {
    auto& instance1 = ExampleDerived::GetInstance_Meyers();
    auto& instance2 = ExampleDerived::GetInstance_Meyers();

    // Test that the instances are the same (Singleton check using Meyers)
    EXPECT_EQ(&instance1, &instance2); // Compare addresses of references
}

TEST(BaseObjectTest, MeyersNewInstanceTest) {
    auto& instance1 = ExampleDerived::GetInstance_Meyers();
    auto& newInstance = ExampleDerived::GetInstance_Meyers(true); // Explicitly create a new instance

    // Test that newInstance is different from the singleton instance (Meyers)
    EXPECT_NE(&instance1, &newInstance); // Ensure they are different instances
}

TEST(BaseObjectTest, MeyersThreadSafeSingletonTest) {
    const int thread_count = 10;
    std::vector<std::thread> threads;
    std::vector<ExampleDerived*> instances(thread_count);
    std::mutex instanceMutex;

    // Create multiple threads to access the singleton instance
    for (int i = 0; i < thread_count; ++i) {
        threads.emplace_back([&instances, &instanceMutex, i]() {
            auto& instance = ExampleDerived::GetInstance_Meyers();
            std::lock_guard<std::mutex> guard(instanceMutex);
            instances[i] = &instance;
        });
    }

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    // Check that all instances are the same
    for (int i = 1; i < thread_count; ++i) {
        EXPECT_EQ(instances[0], instances[i]);
    }
}
#endif