#include <iostream>
#include <chrono>
#include <memory>
#include <windows.h>
#include <thread>
#include <vector>

static bool s_Running = true;

void Do_Something() 
{
    int num = 5;
}

void Do_Something_With_Pointer()
{
    size_t* i = new size_t[5];
    delete i;
}

void Do_Something_With_Smarth_Pointers()
{
    std::unique_ptr<size_t> i = std::make_unique<size_t>(5);
}

void Escape_Key_Is_Preseed()
{
    while(s_Running)
    {
        if((GetKeyState(VK_ESCAPE) & 0x8000))
            s_Running = false;
    }
}

void Stack()
{

    while(s_Running)
    {

        auto start = std::chrono::high_resolution_clock::now();

            for (size_t i = 0; i < 10'000'000; i++)
                Do_Something();

        auto end   = std::chrono::high_resolution_clock::now();

        std::cout << "Stack memory: \t\t" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "\tmilliseconds" << std::endl;

    }

}

void Heap() 
{

    while(s_Running)
    {

        auto start = std::chrono::high_resolution_clock::now();

            for (size_t i = 0; i < 10'000'000; i++)
                Do_Something_With_Pointer();

        auto end   = std::chrono::high_resolution_clock::now();

        std::cout << "Heap memory: \t\t" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "\tmilliseconds" << std::endl;

    }

}

void Heap_Smart()
{

    while(s_Running)
    {

        auto start = std::chrono::high_resolution_clock::now();

            for (size_t i = 0; i < 10'000'000; i++)
                Do_Something_With_Smarth_Pointers();

        auto end   = std::chrono::high_resolution_clock::now();

        std::cout << "Heap memory Smarth:  \t" << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "\tmilliseconds" << std::endl;

    }

}

int main ()
{
    
    

    std::vector<std::thread> threads;

    threads.push_back(std::thread(Stack));
    threads.push_back(std::thread(Heap));
    threads.push_back(std::thread(Heap_Smart));
    threads.push_back(std::thread(Escape_Key_Is_Preseed));

    std::cout << "Hello thread" << std::endl;
        
        
    for(auto& thread : threads)
        thread.join();    

}