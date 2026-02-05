module CircularQueue (
    input            clock,
    input            push,
    input            pop,
    input            reset,
    input      [7:0] dataIn,
    output     [7:0] dataOut,
    output reg [3:0] size = 0,
    output           isFull,
    output           isEmpty
);
    reg  [2:0] front = 0;
    wire [2:0] back = front + size[2:0];
    wire [7:0] ramOut;
    assign isFull  = (size == 8);
    assign isEmpty = (size == 0);
    reg [7:0] displayOut;
    assign dataOut = displayOut;
    wire write = (push && !isFull);

    SimpleDualPortRAM ram (
        .addra(back),
        .clka (clock),
        .dina (dataIn),
        .ena  (1),
        .wea  (write),
        .addrb(front),
        .clkb (clock),
        .doutb(ramOut),
        .enb  (1)
    );

    always @(posedge clock) begin
        if (reset) begin
            front      <= 0;
            size       <= 0;
            displayOut <= 0;
        end else begin
            case ({
                push, pop
            })
                // Pop only
                2'b01: begin
                    if (!isEmpty) begin
                        front      <= front + 1;
                        size       <= size - 1;
                        displayOut <= ramOut;
                    end
                end
                // Push only
                2'b10: begin
                    if (!isFull) begin
                        size <= size + 1;
                    end
                end
                // // Push and pop simultaneously
                // 2'b11: begin
                //     write <= 1;
                //     front <= front + 1;
                // end
                default: begin
                end
            endcase
        end
    end

endmodule
