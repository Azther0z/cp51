package logic.unit;

public class FlyingUnit extends BaseUnit {

	public FlyingUnit(int startColumn, int startRow, boolean isWhite, String name) {
		super(startColumn, startRow, isWhite, name);
		this.setHp(2);
		this.setFlying(true);
	}

	@Override
	public boolean move(int direction) {
		if (!(0 <= direction && direction < 4)) {
			return false;
		}
		int[] diffRow = { 2, 0, -2, 0 };
		int[] diffColumn = { 0, 2, 0, -2 };
		if (valid(this.getColumn() + diffColumn[direction]) && valid(this.getRow() + diffRow[direction])) {
			this.setColumn(this.getColumn() + diffColumn[direction]);
			this.setRow(this.getRow() + diffRow[direction]);
			return true;
		}
		return false;
	}
}
