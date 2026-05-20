package entity.container;

import entity.base.Container;
import entity.base.Ingredient;
import logic.StringUtil;

public class Dish extends Container {

	private int dirty;

	public Dish(int dirty) {
		super("Dish", 4);
		this.setDirty(dirty);
	}

	public Dish() {
		this(0);
	}

	@Override
	public boolean verifyContent(Ingredient i) {
		if (!this.isDirty() && i.isEdible()) {
			return true;
		}
		return false;
	}

	public void clean(int amount) {
		this.setDirty(this.getDirty() - amount);
	}

	public boolean isDirty() {
		if (this.getDirty() > 0) {
			return true;
		}
		return false;
	}

	public int getDirty() {
		return dirty;
	}

	public void setDirty(int dirty) {
		if (dirty < 0) {
			dirty = 0;
		}
		this.dirty = dirty;
		if (this.dirty > 0) {
			this.setName("Dirty Dish");
		} else {
			this.setName("Dish");
		}
	}

	@Override
	public String toString() {
		if (this.isDirty()) {
			return StringUtil.formatNamePercentage(this.getName(), this.getDirty());
		}
		return super.toString();
	}

}
