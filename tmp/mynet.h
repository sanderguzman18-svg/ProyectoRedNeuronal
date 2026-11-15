
#include <eml_net.h>
static const float mynet_layer_0_biases[3] = { -0.492986f, 0.296325f, 0.640261f };
static const float mynet_layer_0_weights[9] = { -0.120554f, -0.356811f, -0.719832f, -0.968889f, 0.116829f, 0.114619f, 0.730835f, -1.883854f, 1.125427f };
static float mynet_buf1[3];
static float mynet_buf2[3];
static const EmlNetLayer mynet_layers[1] = { 
{ 3, 3, mynet_layer_0_weights, mynet_layer_0_biases, EmlNetActivationSoftmax } };
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
    