
#include <eml_net.h>
static const float modelo_frutas_layer_0_biases[3] = { -0.492986f, 0.296325f, 0.640261f };
static const float modelo_frutas_layer_0_weights[9] = { -0.120554f, -0.356811f, -0.719832f, -0.968889f, 0.116829f, 0.114619f, 0.730835f, -1.883854f, 1.125427f };
static float modelo_frutas_buf1[3];
static float modelo_frutas_buf2[3];
static const EmlNetLayer modelo_frutas_layers[1] = { 
{ 3, 3, modelo_frutas_layer_0_weights, modelo_frutas_layer_0_biases, EmlNetActivationSoftmax } };
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
    