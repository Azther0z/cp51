package logic.unit;

import java.util.ArrayList;

public class RangeUnit extends BaseUnit {

	public RangeUnit(int startColumn, int startRow, boolean isWhite, String name) {
		super(startColumn, startRow, isWhite, name);
		this.setHp(2);
	}

	@Override
	public void attack(ArrayList<BaseUnit> targetPieces) {
		for (BaseUnit target : targetPieces) {
			if (this.isWhite() && this.getRow() + 1 == target.getRow() && this.getColumn() == target.getColumn()) {
				System.out.println(this.getName() + " attacks " + target.getName());
				target.setHp(target.getHp() - this.getPower());
			} else if (!this.isWhite() && this.getRow() - 1 == target.getRow()
					&& this.getColumn() == target.getColumn()) {
				System.out.println(this.getName() + " attacks " + target.getName());
				target.setHp(target.getHp() - this.getPower());
			}
		}
	}
}
