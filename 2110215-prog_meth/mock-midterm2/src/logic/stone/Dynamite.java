package logic.stone;

import java.util.ArrayList;

import utils.GameUtilities;

public class Dynamite extends Stone{

	public Dynamite(int posX, int posY) {
		super(posX, posY);
	}
	
	@Override
	public void destroy() {
		GameUtilities.removeStone(this);
		ArrayList<Stone> stones = GameUtilities.getAdjacentStones(this.getPosX(), this.getPosY());
		for(Stone stone:stones) {
			stone.destroy();
		}
	}
}
