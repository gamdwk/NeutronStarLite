#include <torch/torch.h>
#include <cuda_runtime.h>
#include <iostream>
// 定义一个简单的神经网络类
struct Net :torch::nn::Module {
    torch::Tensor W0, W1;
    Net() {
        W0 = register_parameter("W0", torch::randn({784, 64}));
        W1 = register_parameter("W1", torch::randn({64, 10}));
    }
    torch::Tensor forward(torch::Tensor x) {
        x = x.mm(W0);
        x = torch::relu(x);
        x = x.mm(W1);
        return torch::log_softmax(x, /*dim=*/1);
    }
};

int main() {
    int device_id = 1; // 设定使用的 GPU 设备ID  
    cudaSetDevice(device_id); // 设置当前设备  

    // 创建一个在指定 GPU 上的张量  
    at::Tensor tensor = torch::rand({2, 3}, torch::Device(torch::kCUDA, 1));   
    at::Tensor tensor1 = torch::rand({2, 3}).cuda();   
    cudaStream_t stream;
    std::cout << "Tensor on GPU: \n" << tensor + tensor1 << std::endl;  
    std::cout << "Tensor device" << tensor.device() << std::endl;  
    std::cout << "Tensor1 device" << tensor1.device() << std::endl;  
    return 0;
}