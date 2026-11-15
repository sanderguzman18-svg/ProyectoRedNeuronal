
#include <eml_net.h>
static const float mynet_layer_0_biases[2] = { 0.251788f, -0.251788f };
static const float mynet_layer_0_weights[6] = { 1.151868f, 0.710759f, -0.510850f, 0.868443f, 0.418403f, -0.267507f };
static float mynet_buf1[3];
static float mynet_buf2[3];
static const EmlNetLayer mynet_layers[1] = { 
{ 2, 3, mynet_layer_0_weights, mynet_layer_0_biases, EmlNetActivationSoftmax } };
static EmlNet mynet = { 1, mynet_layers, mynet_buf1, mynet_buf2, 3 };

    int32_t
    mynet_predict(const float *features, int32_t n_features)
    {
        return eml_net_predict(&mynet, features, n_features);
    }
    

    int32_t
    mynet_regress(const float *features, int32_t n_features, float *out, int32_t out_length)
    {
        return eml_net_regress(&mynet, features, n_features, out, out_length);
    }
    

    float
    mynet_regress1(const float *features, int32_t n_features)
    {
        return eml_net_regress1(&mynet, features, n_features);
    }
    