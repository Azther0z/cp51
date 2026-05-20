package logic.stone;

import logic.game.GameManager;
import utils.GameUtilities;

public class WalkingStone extends Stone{

	public WalkingStone(int posX, int posY) {
		super(posX, posY);
	}
	
	public void dig(int digPower) {
		destroy();
		if(digPower>1) {
//			GameManager instance = GameManager.getInstance();
			GameManager.getInstance().addScore(1);
		}
	}
	
	public void walk() {
		GameUtilities.moveWalkingRock(this);
	}
}
