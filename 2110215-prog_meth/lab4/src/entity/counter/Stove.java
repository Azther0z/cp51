package entity.counter;

import entity.base.Item;
import entity.base.Updatable;
import entity.container.Pan;
import logic.Player;

public class Stove extends Counter implements Updatable{
	public Stove(Item content) {
		super("Stove");
		this.setPlacedContent(content);
	}

	public Stove() {
		this(null);
	}

	public void interact(Player p) {
		if (!this.isPlacedContentEmpty()) {
			super.interact(p);
			return;
		}
		if (p.isHandEmpty()) {
			return;
		}
		if (p.getHoldingItem() instanceof Pan) {
			super.interact(p);
		}
	}

	public void update() {
		if (this.isPlacedContentEmpty()) {
			return;
		}
		if (this.getPlacedContent() instanceof Pan) {
			Pan pan = (Pan) this.getPlacedContent();
			pan.cook();
		}
	}
}
