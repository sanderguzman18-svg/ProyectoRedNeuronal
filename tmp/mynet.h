
#include <eml_net.h>
static const float mynet_layer_0_biases[8] = { -0.079922f, 0.000000f, -0.092758f, 0.298244f, 0.006979f, 0.000000f, -0.299031f, -0.048692f };
static const float mynet_layer_0_weights[24] = { -0.601667f, -0.333485f, 0.431607f, 0.305283f, 0.768106f, -0.457698f, 0.595265f, 0.054028f, 0.466558f, -0.387498f, -0.393478f, 0.584090f, 0.510322f, -0.109894f, -0.751388f, -0.386472f, 0.430039f, 0.336608f, -0.813752f, -1.272974f, 0.412503f, 0.084145f, 0.942120f, -0.678888f };
static const float mynet_layer_1_biases[3] = { -0.263403f, 0.139783f, 0.337105f };
static const float mynet_layer_1_weights[24] = { -0.104262f, 0.333209f, -0.362734f, 0.294736f, -0.278412f, 0.122306f, 0.369173f, 0.452685f, -1.624789f, -0.996527f, 0.110094f, -0.162090f, 0.506303f, 0.406962f, 0.777475f, 0.025136f, 0.603313f, -0.610662f, 1.083577f, -0.002957f, -0.295776f, -0.239506f, 0.600204f, -0.666800f };
static float mynet_buf1[8];
static float mynet_buf2[8];
static const EmlNetLayer mynet_layers[2] = { 
{ 8, 3, mynet_layer_0_weights, mynet_layer_0_biases, EmlNetActivationRelu }, 
{ 3, 8, mynet_layer_1_weights, mynet_layer_1_biases, EmlNetActivationSoftmax } };
static EmlNet mynet = { 2, mynet_layers, mynet_buf1, mynet_buf2, 8 };

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
    