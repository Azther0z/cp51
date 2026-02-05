module TopModule (
    input        clock,
    input        buttonLeft,      // Active high
    input        buttonRight,     // Active high
    input        buttonCenter,    // Active high
    input  [7:0] switch,          // Active high
    output [1:0] led,             // Active high
    output [3:0] digitSelector,   // Digit selector, active low
    output [7:0] segmentSelector  // Segment selector, active low
);

    wire pushSignal;
    SinglePulser #(
        .SAMPLING_RATE(5e7),
        .COUNTER_WIDTH(32)
    ) pushPulser (
        .clock  (clock),
        .reset  (buttonCenter),
        .dataIn (buttonLeft),
        .dataOut(pushSignal)
    );

    wire popSignal;
    SinglePulser #(
        .SAMPLING_RATE(5e7),
        .COUNTER_WIDTH(32)
    ) popPulser (
        .clock  (clock),
        .reset  (buttonCenter),
        .dataIn (buttonRight),
        .dataOut(popSignal)
    );

    wire [7:0] displayData;
    wire [3:0] displaySize;
    CircularQueue queue (
        .clock  (clock),
        .push   (pushSignal),
        .pop    (popSignal),
        .reset  (buttonCenter),
        .dataIn (switch),
        .dataOut(displayData),
        .size   (displaySize),
        .isFull (led[0]),
        .isEmpty(led[1])
    );

    SevenSegment display (
        .clock          (clock),
        .reset          (buttonCenter),
        .digit1         (displaySize),
        .digit2         (0),
        .digit3         (displayData[3:0]),
        .digit4         (displayData[7:4]),
        .digitSelector  (digitSelector),
        .segmentSelector(segmentSelector)
    );

endmodule
