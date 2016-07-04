#include <iostream>
#include <thread>

class func{
private:
    int & i;
    func(int & i_):i{i_}{}
    void operator()(){
        for(unsigned j = 0; j<1000; j++){
            i++;
        }
    }
};



void hello(){
    std::cout << "Hello Concurrent World\n";
}

int main(){
    std::thread t(hello);
    t.join();  // ensures that the main thread waits for the newly created thread
    return 0;
}
