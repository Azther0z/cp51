package card.base;

//You CAN modify the first line
abstract public class Card implements Cloneable {

	/// You can modify code below ///
	private String name;
	private String flavorText;
	private int bloodCost;

	public Card(String name, String flavorText, int bloodCost) {
		super();
		this.setName(name);
		this.setFlavorText(flavorText);
		this.setBloodCost(bloodCost);
	}

	abstract public String toString();

	/// You can modify code above ///

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getFlavorText() {
		return flavorText;
	}

	public void setFlavorText(String flavorText) {
		this.flavorText = flavorText;
	}

	public int getBloodCost() {
		return bloodCost;
	}

	public void setBloodCost(int bloodCost) {
		if (bloodCost < 0) {
			this.bloodCost = 0;
		} else {
			this.bloodCost = bloodCost;
		}
	}

	public boolean equals(UnitCard other) {
		return this.getName().equals(other.getName());
	}

	public Object clone() throws CloneNotSupportedException {
		return super.clone();
	}

}