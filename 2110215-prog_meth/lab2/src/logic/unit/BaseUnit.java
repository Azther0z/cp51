package logic.unit;

import java.util.ArrayList;

public class BaseUnit {
	private int row;
	private int column;
	private boolean isWhite;
	private String name;
	protected int hp;
	protected int power;
	protected boolean isFlying;

	public BaseUnit(int startColumn, int startRow, boolean isWhite, String name) {
		this.setPower(1);
		this.setFlying(false);
		this.setHp(2);
		this.setColumn(startColumn);
		this.setRow(startRow);
		this.setWhite(isWhite);
		this.setName(name);
	}

	protected boolean valid(int x) {
		return 0 <= x && x <= 4;
	}

	public boolean move(int direction) {
		if (!(0 <= direction && direction < 4)) {
			return false;
		}
		int[] diffRow = { 1, 0, -1, 0 };
		int[] diffColumn = { 0, 1, 0, -1 };
		if (valid(this.getColumn() + diffColumn[direction]) && valid(this.getRow() + diffRow[direction])) {
			this.setColumn(this.getColumn() + diffColumn[direction]);
			this.setRow(this.getRow() + diffRow[direction]);
			return true;
		}
		return false;
	}

	public void attack(ArrayList<BaseUnit> targetPieces) {
		for (BaseUnit target : targetPieces) {
			if (!target.isFlying() && this.getColumn() == target.getColumn() && this.getRow() == target.getRow()) {
				System.out.println(this.getName() + " attacks " + target.getName());
				target.setHp(target.getHp() - this.power);
			}
		}
	}

	public int getRow() {
		return row;
	}

	public void setRow(int row) {
		if (row < 0) {
			this.row = 0;
		} else if (row > 4) {
			this.row = 4;
		} else {
			this.row = row;
		}
	}

	public int getColumn() {
		return column;
	}

	public void setColumn(int column) {
		if (column < 0) {
			this.column = 0;
		} else if (column > 4) {
			this.column = 4;
		} else {
			this.column = column;
		}
	}

	public boolean isWhite() {
		return isWhite;
	}

	public void setWhite(boolean isWhite) {
		this.isWhite = isWhite;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getHp() {
		return hp;
	}

	public void setHp(int hp) {
		this.hp = hp;
	}

	public int getPower() {
		return power;
	}

	public void setPower(int power) {
		this.power = power;
	}

	public boolean isFlying() {
		return isFlying;
	}

	public void setFlying(boolean isFlying) {
		this.isFlying = isFlying;
	}

}
