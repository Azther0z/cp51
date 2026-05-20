package test.student;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.fail;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import card.base.Card;
import card.type.BuffSpellCard;
import card.type.NormalUnitCard;
import deck.Deck;
import deck.InsertCardFailedException;
import deck.RemoveCardFailedException;

public class TestDeck {

	Deck deck1, deck2, deck3;

	NormalUnitCard NormalUnit1 = new NormalUnitCard("Normal Unit 1", "normal unit 1", 0, 1, 1);
	NormalUnitCard NormalUnit2 = new NormalUnitCard("Normal Unit 2", "normal unit 2", 2, 3, 4);
	BuffSpellCard BuffSpellCard1 = new BuffSpellCard("Buff Spell 1", "buff spell 1", 0, false, 1);
	BuffSpellCard BuffSpellCard2 = new BuffSpellCard("Buff Spell 2", "buff spell 2", 2, false, 4);

	Card[] cardList1 = {};

	Card[] cardList2 = { NormalUnit1, NormalUnit1, NormalUnit1, NormalUnit1, NormalUnit2, NormalUnit2, NormalUnit2,
			NormalUnit2 };

	Card[] cardList3 = { NormalUnit1, NormalUnit1, NormalUnit2, NormalUnit2, BuffSpellCard1, BuffSpellCard1,
			BuffSpellCard2, BuffSpellCard2 };

	@BeforeEach
	void setUp() {

		deck1 = new Deck("Test Deck 1", cardList1);

		deck2 = new Deck("Test Deck 2", cardList2);

		deck3 = new Deck("Test Deck 3", cardList3);
	}

	@Test
	void testConstructor() {
		assertEquals("Test Deck 1", deck1.getName());
		assertEquals(0, deck1.getDeckSize());
		for (int i = 0; i < deck1.getDeckSize(); i++) {
			assertEquals(cardList1[i], deck1.getDeckList()[i]);
		}

		assertEquals("Test Deck 2", deck2.getName());
		assertEquals(8, deck2.getDeckSize());
		for (int i = 0; i < deck2.getDeckSize(); i++) {
			assertEquals(cardList2[i], deck2.getDeckList()[i]);
		}

		assertEquals("Test Deck 3", deck3.getName());
		assertEquals(8, deck3.getDeckSize());
		for (int i = 0; i < deck3.getDeckSize(); i++) {
			assertEquals(cardList3[i], deck3.getDeckList()[i]);
		}

	}

	@Test
	void testInsertCard() {
		try {
			deck1.insertCard(BuffSpellCard1);
		} catch (InsertCardFailedException e) {
			fail("InsertCardFailedException deck1 throws error");
		}
		Card[] cardList1New = { BuffSpellCard1 };
		assertEquals(1, deck1.getDeckSize());
		for (int i = 0; i < deck1.getDeckSize(); i++) {
			assertEquals(cardList1New[i], deck1.getDeckList()[i]);
		}

		try {
			deck3.insertCard(BuffSpellCard1);
		} catch (InsertCardFailedException e) {
			fail("InsertCardFailedException deck3 throws error");
		}
		Card[] cardList3New = { NormalUnit1, NormalUnit1, NormalUnit2, NormalUnit2, BuffSpellCard1, BuffSpellCard1,
				BuffSpellCard2, BuffSpellCard2, BuffSpellCard1 };
		assertEquals(9, deck3.getDeckSize());
		for (int i = 0; i < deck3.getDeckSize(); i++) {
			assertEquals(cardList3New[i], deck3.getDeckList()[i]);
		}

	}

	@Test
	void testInsertCardMoreThan4Card() {
		for (int i = 0; i < 4; i++) {
			try {
				deck1.insertCard(BuffSpellCard1);
			} catch (InsertCardFailedException e) {
				fail("You insert too many " + BuffSpellCard1.getName() + " Card)");
			}
		}
		assertThrows(InsertCardFailedException.class, () -> {
			deck1.insertCard(BuffSpellCard1);
		});

	}

	// Fill Code Here!!!
	// 1.testRemoveCard
	// 2.testNonExsistanceRemoveCard
	@Test
	void testRemoveCard() {
		// Remove index 0
		Card[] listToRemove = { NormalUnit1, NormalUnit2, BuffSpellCard1, BuffSpellCard2 };
		Card[] listChecker = { NormalUnit2, BuffSpellCard1, BuffSpellCard2 };
		Deck deckToRemove = new Deck("Deck to Remove", listToRemove);
		Deck deckChecker = new Deck("Deck to Check", listChecker);
		try {
			Card removed = deckToRemove.removeCard(0);
			assertEquals(removed, NormalUnit1);
			assertEquals(deckToRemove.getDeckSize(), deckChecker.getDeckSize());
			for (int i = 0; i < deckToRemove.getDeckSize(); i++) {
				assertEquals(deckToRemove.getDeckList()[i], deckChecker.getDeckList()[i]);
			}
		} catch (RemoveCardFailedException e) {
			// TODO Auto-generated catch block
			fail("RemoveCardFailedException deckToRemove throws error");
		}
		// Remove index 1
		Card[] listChecker2 = { NormalUnit1, BuffSpellCard1, BuffSpellCard2 };
		Deck deckToRemove2 = new Deck("Deck to Remove", listToRemove);
		Deck deckChecker2 = new Deck("Deck to Check", listChecker2);
		try {
			Card removed = deckToRemove2.removeCard(1);
			assertEquals(removed, NormalUnit2);
			assertEquals(deckToRemove2.getDeckSize(), deckChecker2.getDeckSize());
			for (int i = 0; i < deckToRemove2.getDeckSize(); i++) {
				assertEquals(deckToRemove2.getDeckList()[i], deckChecker2.getDeckList()[i]);
			}
		} catch (RemoveCardFailedException e) {
			// TODO Auto-generated catch block
			fail("RemoveCardFailedException deckToRemove throws error");
		}
		// Remove last card
		Card[] listToRemove3 = { BuffSpellCard2 };
		Deck deckToRemove3 = new Deck("Deck to Remove", listToRemove3);
		try {
			Card removed = deckToRemove3.removeCard(0);
			assertEquals(removed, BuffSpellCard2);
			assertEquals(deckToRemove3.getDeckSize(), 0);
		} catch (RemoveCardFailedException e) {
			// TODO Auto-generated catch block
			fail("RemoveCardFailedException deckToRemove throws error");
		}
	}

	@Test
	void testRemoveNonExistanceCard() {
		Card[] listToRemove1 = { NormalUnit1, null, NormalUnit2 };
		Deck deckToRemove1 = new Deck("Deck to Remove", listToRemove1);
		assertThrows(RemoveCardFailedException.class, () -> {
			deckToRemove1.removeCard(1);
		});
		assertThrows(RemoveCardFailedException.class, () -> {
			deckToRemove1.removeCard(3);
		});
	}

}
