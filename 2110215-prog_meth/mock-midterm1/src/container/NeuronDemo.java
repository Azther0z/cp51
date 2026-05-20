package container;

public class NeuronDemo {
	private Neuron n;
	
	public void demonstrate() {
		double[] weights = {0.2,0.3,0.4};
		double bias = 0.2;
		this.n = new Neuron(weights,bias);
		Neuron.setRangeWeight(0.1,0.7);
		this.n.setGradient(0.6);
		this.n.setValue(1);
	}

	public Neuron getN() {
		return n;
	}

	public void setN(Neuron n) {
		this.n = n;
	}
}
