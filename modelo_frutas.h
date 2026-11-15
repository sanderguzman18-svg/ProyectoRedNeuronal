
#include <eml_net.h>
static const float modelo_frutas_layer_0_biases[2] = { 0.251788f, -0.251788f };
static const float modelo_frutas_layer_0_weights[6] = { 1.151868f, 0.710759f, -0.510850f, 0.868443f, 0.418403f, -0.267507f };
static float modelo_frutas_buf1[3];
static float modelo_frutas_buf2[3];
static const EmlNetLayer modelo_frutas_layers[1] = { 
{ 2, 3, modelo_frutas_layer_0_weights, modelo_frutas_layer_0_biases, EmlNetActivationSoftmax } };
static EmlNet modelo_frutas = { 1, modelo_frutas_layers, modelo_frutas_buf1, modelo_frutas_buf2, 3 };

    int32_t
    modelo_frutas_predict(const float *features, int32_t n_features)
    {
        return eml_net_predict(&modelo_frutas, features, n_features);
    }
    

    int32_t
    modelo_frutas_regress(const float *features, int32_t n_features, float *out, int32_t out_length)
    {
        return eml_net_regress(&modelo_frutas, features, n_features, out, out_length);
    }
    

    float
    modelo_frutas_regress1(const float *features, int32_t n_features)
    {
        return eml_net_regress1(&modelo_frutas, features, n_features);
    }
    