package test.student;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import card.base.UnitCard;
import card.type.LeaderUnitCard;

public class TestLeaderUnitCard {
	LeaderUnitCard leaderUnit1;
	UnitCard leaderUnit2;
	LeaderUnitCard leaderUnit3;
	LeaderUnitCard oppoUnit1;
	LeaderUnitCard nUnit1;
	LeaderUnitCard nUnit2;
	LeaderUnitCard nUnit3;
	UnitCard[] unitList;

	@BeforeEach
	void setUp() {
		leaderUnit1 = new LeaderUnitCard("Leader", "He's a Leader", 2, 3, 2, 3, 2);
		leaderUnit2 = new LeaderUnitCard("Boss", "Worse version of Leader", 4, 1, 4, 1, 2);
		leaderUnit3 = new LeaderUnitCard("Leader", "He's a Leader", -1, -3, -2, -3, -2);
		oppoUnit1 = new LeaderUnitCard("Opponent", "I'm an opponent", 0, 1, 5, 0, 0);
		nUnit1 = new LeaderUnitCard("Unit1", "1", 0, 1, 2, 0, 0);
		nUnit2 = new LeaderUnitCard("Unit2", "2", 0, 3, 1, 0, 0);
		nUnit3 = new LeaderUnitCard("Unit3", "3", 0, 2, 4, 0, 0);
		unitList = new UnitCard[] { nUnit1, nUnit2, nUnit3 };
	}

	@Test
	void testConstructor() {

		assertEquals("Leader", leaderUnit1.getName());
		assertEquals("He's a Leader", leaderUnit1.getFlavorText());
		assertEquals(2, leaderUnit1.getBloodCost());
		assertEquals(3, leaderUnit1.getPower());
		assertEquals(2, leaderUnit1.getHealth());
		assertEquals(3, leaderUnit1.getBuffPower());
		assertEquals(2, leaderUnit1.getBuffHealth());

	}

	@Test
	void testConstructorNegativeValue() {

		assertEquals("Leader", leaderUnit3.getName());
		assertEquals("He's a Leader", leaderUnit3.getFlavorText());
		assertEquals(0, leaderUnit3.getBloodCost());
		assertEquals(0, leaderUnit3.getPower());
		assertEquals(0, leaderUnit3.getHealth());
		assertEquals(0, leaderUnit3.getBuffPower());
		assertEquals(0, leaderUnit3.getBuffHealth());

	}

	@Test
	void testSetBuffPower() {
		leaderUnit1.setBuffPower(5);
		assertEquals(5, leaderUnit1.getBuffPower());
		leaderUnit1.setBuffPower(-1);
		assertEquals(0, leaderUnit1.getBuffPower());

	}

	// Fill Code Here!!!
	// 1.testSetBuffHealth
	// 2.testAttack (Must test a case of oppoUnit1 take damage exceed its health,
	// not including this case will only give you half a score)
	// 3.testBuffUnit
	@Test
	void testSetBuffHealth() {
		leaderUnit1.setBuffHealth(5);
		assertEquals(5, leaderUnit1.getBuffHealth());
		leaderUnit1.setBuffHealth(-1);
		assertEquals(0, leaderUnit1.getBuffHealth());

	}

	@Test
	void testAttack() {
		// 5-3=2 3 damage
		int damage1 = leaderUnit1.attackUnit(oppoUnit1);
		assertEquals(damage1, 3);
		assertEquals(oppoUnit1.getHealth(), 2);
		// 2-1=1 1 damage
		int damage2 = leaderUnit2.attackUnit(oppoUnit1);
		assertEquals(damage2, 1);
		assertEquals(oppoUnit1.getHealth(), 1);
		// 1-3=-2=0 1 damage
		int damage3 = leaderUnit1.attackUnit(oppoUnit1);
		assertEquals(damage3, 1);
		assertEquals(oppoUnit1.getHealth(), 0);
		// 0-3=-3=0 0 damage
		int damage4 = leaderUnit1.attackUnit(oppoUnit1);
		assertEquals(damage4, 0);
		assertEquals(oppoUnit1.getHealth(), 0);
	}

	@Test
	void testBuffUnit() {
		leaderUnit1.buffUnit(unitList);
		// Power 1 3 2 +3
		assertEquals(unitList[0].getPower(), 4);
		assertEquals(unitList[1].getPower(), 6);
		assertEquals(unitList[2].getPower(), 5);
		// Health 2 1 4 +2
		assertEquals(unitList[0].getHealth(), 4);
		assertEquals(unitList[1].getHealth(), 3);
		assertEquals(unitList[2].getHealth(), 6);
		leaderUnit3.buffUnit(unitList);
		// Power 4 6 5 +0
		assertEquals(unitList[0].getPower(), 4);
		assertEquals(unitList[1].getPower(), 6);
		assertEquals(unitList[2].getPower(), 5);
		// Health 4 3 6 +0
		assertEquals(unitList[0].getHealth(), 4);
		assertEquals(unitList[1].getHealth(), 3);
		assertEquals(unitList[2].getHealth(), 6);
		LeaderUnitCard leaderUnit4 = (LeaderUnitCard) leaderUnit2;
		leaderUnit4.setBuffHealth(8);
		leaderUnit4.buffUnit(unitList);
		// Power 4 6 5 +1
		assertEquals(unitList[0].getPower(), 5);
		assertEquals(unitList[1].getPower(), 7);
		assertEquals(unitList[2].getPower(), 6);
		// Health 4 3 6 +8
		assertEquals(unitList[0].getHealth(), 12);
		assertEquals(unitList[1].getHealth(), 11);
		assertEquals(unitList[2].getHealth(), 14);
	}
}
