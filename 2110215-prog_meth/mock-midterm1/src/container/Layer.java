package container;

import function.Function;
import util.GenRandom;
import util.Activation;

public class Layer {
	private Neuron[] neurons;
	private Function function;

	public Layer(int inNeurons, int nNeurons, Function function) {
		this.setFunction(function);
		Neuron[] neurons = new Neuron[nNeurons];
		for (int n = 0; n < nNeurons; n++) {
			double[] weights = new double[inNeurons];
			for (int i = 0; i < inNeurons; i++) {
				weights[i] = GenRandom.randomDouble(Neuron.getMinWeightValue(), Neuron.getMaxWeightValue());
			}
			double bias = GenRandom.randomDouble(0, 1);
			neurons[n] = new Neuron(weights, bias);
		}
		this.setNeurons(neurons);
	}

	public Layer(double[] input) {
		this.neurons = new Neuron[input.length];
		for (int i = 0; i < input.length; i++) {
			neurons[i] = new Neuron(input[i]);
		}
		this.function = null;
	}

	public double applyActivation(double x) throws IllegalArgumentException {
		if (this.function != Function.RELU && this.function != Function.SIGMOID && this.function != Function.TANH) {
			throw new IllegalArgumentException("Unknown activation function: " + this.function);
		}
		double y = 0;
		if (this.function == Function.RELU) {
			y = Activation.relu(x);
		}
		if (this.function == Function.SIGMOID) {
			y = Activation.sigmoid(x);
		}
		if (this.function == Function.TANH) {
			y = Activation.tanh(x);
		}
		return y;
	}

	public double applyActivationDerivative(double x) throws IllegalArgumentException {
		if (this.function != Function.RELU && this.function != Function.SIGMOID && this.function != Function.TANH) {
			throw new IllegalArgumentException("Unknown activation function: " + this.function);
		}
		double y = 0;
		if (this.function == Function.RELU) {
			y = Activation.reluDerivative(x);
		}
		if (this.function == Function.SIGMOID) {
			y = Activation.sigmoidDerivative(x);
		}
		if (this.function == Function.TANH) {
			y = Activation.tanhDerivative(x);
		}
		return y;
	}

	public Neuron[] getNeurons() {
		return neurons;
	}

	public void setNeurons(Neuron[] neurons) {
		this.neurons = neurons;
	}

	public Function getFunction() {
		return function;
	}

	public void setFunction(Function function) {
		this.function = function;
	}

}
