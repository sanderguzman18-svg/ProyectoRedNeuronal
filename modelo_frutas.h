
#include <eml_net.h>
static const float modelo_frutas_layer_0_biases[8] = { 0.000000f, -0.017721f, 0.016248f, -0.051157f, 0.000000f, 0.000000f, 0.000000f, 0.437577f };
static const float modelo_frutas_layer_0_weights[24] = { -0.665408f, 0.377959f, 0.075990f, 0.690256f, -0.102201f, -0.610155f, 0.010610f, -0.262039f, -0.275172f, 0.686373f, 0.884925f, -0.512075f, -0.510542f, -0.601128f, -0.721441f, 0.797477f, -0.281681f, -1.584662f, -1.824871f, 0.473738f, 0.099565f, -0.218633f, 0.357551f, 1.327554f };
static const float modelo_frutas_layer_1_biases[3] = { 0.150279f, -0.006838f, -0.064750f };
static const float modelo_frutas_layer_1_weights[24] = { 0.591415f, -0.672264f, -0.375629f, -0.534154f, -0.104421f, -0.783861f, -0.207511f, 0.876483f, -0.386927f, 0.017990f, -0.954205f, 0.019471f, 0.485377f, 0.688639f, 0.435442f, 0.732441f, -0.408251f, -0.403233f, -0.343688f, -0.236398f, 0.555023f, -0.506615f, -0.304139f, 0.998184f };
static float modelo_frutas_buf1[8];
static float modelo_frutas_buf2[8];
static const EmlNetLayer modelo_frutas_layers[2] = { 
{ 8, 3, modelo_frutas_layer_0_weights, modelo_frutas_layer_0_biases, EmlNetActivationRelu }, 
{ 3, 8, modelo_frutas_layer_1_weights, modelo_frutas_layer_1_biases, EmlNetActivationSoftmax } };
static EmlNet modelo_frutas = { 2, modelo_frutas_layers, modelo_frutas_buf1, modelo_frutas_buf2, 8 };

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
    