#include <iostream>

class Widget {
public:
    void doWork() &
    {
        std::cout << "lvalue doWork()" << std::endl;
    }

    void doWork() &&
    {
        std::cout << "rvalue doWork()" << std::endl;
    }
};

Widget makeWidget()
{
    return Widget();
}

int main(int argc, char* argv[])
{
    Widget w = Widget();
    w.doWork();
    Widget().doWork();
    Widget w2 = makeWidget();
    w2.doWork();
    makeWidget().doWork();
}
