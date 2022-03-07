// Enes Şaşmaz 150170090 OOP-HW3 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Neuron
{
private:
    double z;
    double a;
public:
    void setz(const double& value)
    {
        z = value;
    }
    void seta(const double& value)
    {
        a = value;
    }
    void getz()
    {
        return z;
    }
    void geta()
    {
        return a;
    }
    Neuron(double z_value);
    virtual void active() = 0;
};

Neuron::Neuron(double z_value)
{
    setz(z_value);
}

class SigmoidNeuron : public Neuron
{
private:
public:
    SigmoidNeuron(double z_value);
    void avtivate();
};

SigmoidNeuron::SigmoidNeuron(double z_value)
{
    setz(z_value);
}

void SigmoidNeuron::active()
{
    int x = 0;
    x = 1 / (1 + exp(-getz()));
    seta(x);
}

class ReluNeuron : public Neuron
{
private:
public:
    ReluNeuron(double z_value);
    void avtivate();
};

ReluNeuron::ReluNeuron(double z_value)
{
    setz(z_value);
}

void ReluNeuron::avtivate()
{
    int x = 0;
    x = max(0, getz());
    seta(x);
}

class LReluNeuron : public Neuron
{
private:
public:
    LReluNeuron(double z_value);
    void avtivate();
};

LReluNeuron::LReluNeuron(double z_value)
{
    setz(z_value);
}

void LReluNeuron::avtivate()
{
    int x = 0;
    x = max(0.1 * getz(), getz());
    seta(x);
}

class Layer
{
private:
public:
    int j = 0;
    Neuron* neuron_array = new Neuron[];
    Layer(int neuron_number, int type, int inputz);
};

Layer::Layer(int neuron_number, int type, int* inputz)
{
    for (int i = 0; i < neuron_number; i++)
    {
        if (type = 0)
        {
            SigmoidNeuron s1 = SigmoidNeuron(inputz[i]);
            neuron_array[i] = s1;
        }
        if (type = 1)
        {
            LReluNeuron s1 = LReluNeuron(inputz[i]);
            neuron_array[i] = s1;
        }
        if (type = 2)
        {
            ReluNeuron s1 = ReluNeuron(inputz[i]);
            neuron_array[i] = s1;
        }                
    }    
}

class Network
{
private:
public:
    Layer* layer_array = new Layer[];
    Network();
};

Network::Network(int layer_number, int* neuron_number, int* type, int* inputz)
{
    for (int i = 0; i < layer_number; i++)
    {
        Layer l1 = Layer(neuron_number[i], type[i], inputz);
        layer_array[i] = l1;                
    }
}


int main()
{
    int input_layernum, input_neuronnum, input_type, input_z;
    int* input_neuronarr;
    int* input_typearr;
    int* input_zarr;
    cin >> input_layernum;
    for (int i = 0; i < input_layernum; i++)
    {
        cin >> input_neuronnum;
        input_neuronarr[i] = input_neuronnum;
    }

    for (int i = 0; i < input_layernum; i++)
    {
        cin >> input_type;
        input_typearr[i] = input_type;
    }
    
    for (int i = 0; i < input_neuronarr[0]; i++)
    {
        cin >> input_z;
        input_zarr[i] = input_z;
    }


    Network n1 = Network(input_layernum, input_neuronarr, input_typearr, input_zarr)
    
    return 0;
}