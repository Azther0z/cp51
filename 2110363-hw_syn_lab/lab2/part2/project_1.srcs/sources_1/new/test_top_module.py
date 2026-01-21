import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer, ReadOnly
import os
from pathlib import Path
from cocotb_tools.runner import get_runner

# Helper dictionary for mapping hex digits to expected 7-segment CX patterns
# Based on your Verilog segment_map module
SEGMENT_MAP = {
    0: 0x03, 1: 0x9F, 2: 0x25, 3: 0x0D,
    4: 0x99, 5: 0x49, 6: 0x41, 7: 0x1F,
    8: 0x01, 9: 0x09, 10: 0x11, 11: 0xC1,
    12: 0x63, 13: 0x85, 14: 0x61, 15: 0x71
}

@cocotb.test()
async def top_module_test(dut):
    """Test the 7-segment multiplexing display driver"""

    # Start clock (100MHz / 10ns period)
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    # Initialize Inputs
    dut.digit1.value = 0xA  # Should show on AN=1110
    dut.digit2.value = 0xB  # Should show on AN=1101
    dut.digit3.value = 0xC  # Should show on AN=1011
    dut.digit4.value = 0xD  # Should show on AN=0111
    dut.rst.value = 0       # (Your Verilog doesn't use rst for logic, but good practice)

    # Expected sequence (AN, Digit Value)
    # The Verilog uses: counter 0->AN=0111(digit4), 1->AN=1011(digit3)...
    expected_sequence = [
        (0b0111, 0xD), # Digit 4
        (0b1011, 0xC), # Digit 3
        (0b1101, 0xB), # Digit 2
        (0b1110, 0xA), # Digit 1
    ]

    dut._log.info("Starting Multiplexing Test...")

    # Test two full cycles of the 4-digit display
    for cycle in range(2):
        for expected_an, val in expected_sequence:
            await RisingEdge(dut.clk)
            await ReadOnly() # Wait for signals to settle
            
            actual_an = int(dut.AN.value)
            actual_cx = int(dut.CX.value)
            expected_cx = SEGMENT_MAP[val]

            dut._log.info(f"Cycle {cycle} | AN: {bin(actual_an)} CX: {hex(actual_cx)}")

            assert actual_an == expected_an, f"AN error: Expected {bin(expected_an)}, got {bin(actual_an)}"
            assert actual_cx == expected_cx, f"CX error: Expected {hex(expected_cx)}, got {hex(actual_cx)}"

def runner():
    # Make sure filenames match your local files
    verilog_files = ["top_module.v"] 
    top_module = "top_module"
    
    sim = os.getenv("SIM", "icarus")
    proj_path = Path(__file__).resolve().parent
    sources = [proj_path / f for f in verilog_files]

    runner = get_runner(sim)
    runner.build(
        sources=sources,
        hdl_toplevel=top_module,
        always=True,
    )

    runner.test(
        hdl_toplevel=top_module,
        test_module="test_top_module", # Name of this python file
        waves=True,
    )

if __name__ == "__main__":
    runner()