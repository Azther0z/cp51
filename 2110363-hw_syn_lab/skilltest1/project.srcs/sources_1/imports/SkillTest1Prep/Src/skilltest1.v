`timescale 1ns / 1ps

module skilltest1 (
    input  wire       Clk,
    input  wire       Reset,
    input  wire [3:0] Trigger,
    output wire [3:0] BCD0,
    output wire [3:0] BCD1,
    output wire [3:0] BCD2,
    output wire [3:0] BCD3
);
    wire [3:0] clean;
    Debouncer trigger0 (
        .dataIn (Trigger[0]),
        .reset  (Reset),
        .clock  (Clk),
        .dataOut(clean[0])
    );
    Debouncer trigger1 (
        .dataIn (Trigger[1]),
        .reset  (Reset),
        .clock  (Clk),
        .dataOut(clean[1])
    );
    Debouncer trigger2 (
        .dataIn (Trigger[2]),
        .reset  (Reset),
        .clock  (Clk),
        .dataOut(clean[2])
    );
    Debouncer trigger3 (
        .dataIn (Trigger[3]),
        .reset  (Reset),
        .clock  (Clk),
        .dataOut(clean[3])
    );

    wire [15:0] value;
    Trigger operator (
        .trigger(clean),
        .reset  (Reset),
        .clock  (Clk),
        .value  (value)
    );

    Decoder decoder (
        .value(value),
        .clock(Clk),
        .bcd0 (BCD0),
        .bcd1 (BCD1),
        .bcd2 (BCD2),
        .bcd3 (BCD3)
    );

endmodule
