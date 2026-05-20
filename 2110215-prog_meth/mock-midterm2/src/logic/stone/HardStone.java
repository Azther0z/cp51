package logic.stone;

public class HardStone extends Stone {
	protected int durability;

	public HardStone(int posX, int posY, int durability) {
		super(posX, posY);
		this.setDurability(durability);
	}

	@Override
	public void dig(int digPower) {
		this.setDurability(this.getDurability() - digPower);
		if (this.getDurability() <= 0) {
			destroy();
		}
	}

	public int getDurability() {
		return durability;
	}

	public void setDurability(int durability) {
		if (durability < 0) {
			this.durability = 0;
		} else if (durability > 5) {
			this.durability = 5;
		} else {
			this.durability = durability;
		}
	}

}
