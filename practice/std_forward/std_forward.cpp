#include <iostream>
#include <chrono>

class Widget
{
};

void process(const Widget& w)
{
    std::cout << "process(const lvalue ref)" << std::endl;
}

void process(Widget&& rw)
{
    std::cout << "process(rvalue ref)" << std::endl;
}

template<typename T>
void logAndProcess(T&& param)
{
    auto now = std::chrono::system_clock::now();
    process(std::forward<T>(param));
    //process(param);
}

int main(int argc, char* argv[])
{
    Widget w;

    logAndProcess(w);
    logAndProcess(std::move(w));
}
