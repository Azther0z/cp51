module UARTTx (
    input  wire       Clk,
    input  wire       Reset,
    output wire       Tx,
    input  wire [7:0] DataIn,
    input  wire       DataValid,
    output reg        DataReady,
    input  wire       fifo_empty
);
    // Add your code here
    localparam PERIOD = 868;
    localparam IDLE = 0;
    localparam WAIT_DATA = 1;
    localparam START_BIT = 2;
    localparam DATA_BIT = 3;
    localparam STOP_BIT = 4;
    reg [2:0] state;
    reg [7:0] buffer;
    reg [9:0] periodCounter;
    reg [2:0] index;
    reg       TxReg;
    assign Tx = TxReg;

    always @(posedge Clk) begin
        if (Reset) begin
            state     <= IDLE;
            TxReg     <= 1;
            DataReady <= 0;
        end else begin
            case (state)
                IDLE: begin
                    if (!fifo_empty) begin
                        DataReady <= 1;
                        state     <= WAIT_DATA;
                    end
                end
                WAIT_DATA: begin
                    if (DataValid) begin
                        buffer <= DataIn;
                        DataReady     <= 0; // Somehow, DataReady must be zero after exiting WAIT_DATA state
                        periodCounter <= PERIOD;
                        state <= START_BIT;
                    end
                end
                START_BIT: begin
                    TxReg <= 0;
                    if (periodCounter) begin
                        periodCounter <= periodCounter - 1;
                    end else begin
                        periodCounter <= PERIOD;
                        index         <= 0;
                        state         <= DATA_BIT;
                    end
                end
                DATA_BIT: begin
                    TxReg <= buffer[index];
                    if (periodCounter) begin
                        periodCounter <= periodCounter - 1;
                    end else if (!periodCounter && index != 7) begin
                        periodCounter <= PERIOD;
                        index         <= index + 1;
                    end else if (!periodCounter && index == 7) begin
                        periodCounter <= PERIOD;
                        state         <= STOP_BIT;
                    end
                end
                STOP_BIT: begin
                    TxReg <= 1;
                    if (periodCounter) begin
                        periodCounter <= periodCounter - 1;
                    end else begin
                        state <= IDLE;
                    end
                end
                default: ;
            endcase
        end
    end
    // End your code here
endmodule
