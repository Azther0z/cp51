package entity.counter;

import logic.InvalidIngredientException;
import logic.LogicUtil;
import logic.Player;

public class Crate extends Counter {
	private String myIngredient;
	
	public Crate(String s) {
		super(s+" Crate");
		this.setMyIngredient(s);
	}

	public String getMyIngredient() {
		return myIngredient;
	}

	public void setMyIngredient(String myIngredient) {
		this.myIngredient = myIngredient;
	}
	
	public void interact(Player p) {
		if(!p.isHandEmpty()||!super.isPlacedContentEmpty()) {
			super.interact(p);
		}
		else {
			try {
				p.setHoldingItem(LogicUtil.createIngredientFromName(this.getMyIngredient()));
			} catch (InvalidIngredientException e) {
				p.setHoldingItem(null);
			}
		}
	}
}
