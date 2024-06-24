#pragma once
#include <memory>
#include <mutex>

class BaseObjectImpl;

template <typename Derived>
class BaseObject
{
protected:
    static std::shared_ptr<Derived> instance;
    static std::once_flag initFlag;

    // Pimpl idiom for implementation details
    std::shared_ptr<BaseObjectImpl> m_pImpl;

    BaseObject() = default;

public:
    // Thread-safe lazy initialization for singleton instance
    static std::shared_ptr<Derived> GetInstance(bool createNew = false)
    {
        if (createNew)
        {
            // This is for creating a new independent instance
            return std::make_shared<Derived>();
        }
        else
        {
            // Ensures only one singleton instance is created and used
            std::call_once(initFlag, []()
                           { instance = std::make_shared<Derived>(); });
            return instance;
        }
    }

    virtual ~BaseObject() = default;

#ifdef USE_MEYERS_SINGLETON
    /**
     * @brief Version using Meyers' Singleton pattern
     *
     * This version is not chosen because it enforces a single instance without
     * providing flexibility for testing without much wizardry, which I do not wish to perform.
     * The following differs slightly as it provides way to create new instances.
     */
    static Derived &GetInstance_Meyers(bool createNew = false)
    {
        if (createNew)
        {
            return *(new Derived()); // Creates a new instance each time if requested
        }
        else
        {
            static Derived instance; // Meyers' Singleton pattern, thread-safe
            return instance;
        }
    }
#endif
};

// Initialize static members
template <typename Derived>
std::shared_ptr<Derived> BaseObject<Derived>::instance = nullptr;

template <typename Derived>
std::once_flag BaseObject<Derived>::initFlag;

class BaseObjectImpl
{
public:
    virtual ~BaseObjectImpl() = default;
};
