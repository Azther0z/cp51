`timescale 1ns / 1ps

module TopModule (
    input  wire clk,
    input  wire reset,   // BTNC
    output wire uartTx,
    input  wire uartRx
);

    // --- 1. Reset & Debouncing ---
    wire resetCleaned;
    Debouncer debouncer (
        .dataIn (reset),
        .reset  (0),
        .clock  (clk),
        .dataOut(resetCleaned)
    );

    wire        aresetn = ~resetCleaned;

    // --- 2. AXI-Lite Internal Signals ---
    reg  [ 3:0] axi_awaddr;
    reg         axi_awvalid;
    wire        axi_awready;
    reg  [31:0] axi_wdata;
    reg         axi_wvalid;
    wire        axi_wready;
    wire        axi_bvalid;
    reg         axi_bready;
    reg  [ 3:0] axi_araddr;
    reg         axi_arvalid;
    wire        axi_arready;
    wire [31:0] axi_rdata;
    wire        axi_rvalid;
    reg         axi_rready;

    // --- 3. State Machine Logic ---
    localparam IDLE = 3'd0, CHECK_STAT = 3'd1, WAIT_DATA = 3'd2, WRITE_DATA = 3'd3;

    reg [2:0] state;

    always @(posedge clk) begin
        if (!aresetn) begin
            state       <= IDLE;
            axi_awvalid <= 0;
            axi_wvalid  <= 0;
            axi_bready  <= 0;
            axi_arvalid <= 0;
            axi_rready  <= 0;
        end else begin
            case (state)
                IDLE: begin
                    // Prepare to read Status Register (Offset 0x8)
                    axi_araddr  <= 4'h8;
                    axi_arvalid <= 1'b1;
                    axi_rready  <= 1'b1;  // Ready to catch read data
                    state       <= CHECK_STAT;
                end

                CHECK_STAT: begin
                    // 1. Handle Address Handshake
                    if (axi_arready && axi_arvalid) axi_arvalid <= 1'b0;

                    // 2. Handle Data Handshake
                    if (axi_rvalid && axi_rready) begin
                        axi_rready <= 1'b0;

                        if (axi_rdata[0]) begin
                            // Bit 0 is 1: Data is available in RX FIFO!
                            axi_araddr  <= 4'h0;  // Read from offset 0x0
                            axi_arvalid <= 1'b1;
                            axi_rready  <= 1'b1;
                            state       <= WAIT_DATA;
                        end else begin
                            // Nothing received, loop back
                            state <= IDLE;
                        end
                    end
                end

                WAIT_DATA: begin
                    // 1. Handle Address Handshake
                    if (axi_arready && axi_arvalid) axi_arvalid <= 1'b0;

                    // 2. Handle Data Handshake
                    if (axi_rvalid && axi_rready) begin
                        axi_rready  <= 1'b0;

                        // Setup Write to TX FIFO (Offset 0x4)
                        axi_awaddr  <= 4'h4;
                        axi_awvalid <= 1'b1;
                        axi_wdata   <= {24'b0, axi_rdata[7:0] + 8'd1};  // Increment
                        axi_wvalid  <= 1'b1;
                        axi_bready  <= 1'b1;  // Prepare to catch the response

                        state       <= WRITE_DATA;
                    end
                end

                WRITE_DATA: begin
                    // 1. Clear valid signals as soon as IP accepts address/data
                    if (axi_awready && axi_awvalid) axi_awvalid <= 1'b0;
                    if (axi_wready && axi_wvalid) axi_wvalid <= 1'b0;

                    // 2. Wait for the Write Response to complete the transaction safely
                    if (axi_bvalid && axi_bready) begin
                        axi_bready <= 1'b0;
                        state      <= IDLE;  // Done! Go back to polling.
                    end
                end
            endcase
        end
    end

    // --- 4. AXI Uartlite IP Instance ---
    axi_uartlite_0 uart_inst (
        .s_axi_aclk   (clk),
        .s_axi_aresetn(aresetn),
        .s_axi_awaddr (axi_awaddr),
        .s_axi_awvalid(axi_awvalid),
        .s_axi_awready(axi_awready),
        .s_axi_wdata  (axi_wdata),
        .s_axi_wstrb  (4'b1111),
        .s_axi_wvalid (axi_wvalid),
        .s_axi_wready (axi_wready),
        .s_axi_bresp  (),
        .s_axi_bvalid (axi_bvalid),
        .s_axi_bready (axi_bready),
        .s_axi_araddr (axi_araddr),
        .s_axi_arvalid(axi_arvalid),
        .s_axi_arready(axi_arready),
        .s_axi_rdata  (axi_rdata),
        .s_axi_rresp  (),
        .s_axi_rvalid (axi_rvalid),
        .s_axi_rready (axi_rready),
        .rx           (uartRx),
        .tx           (uartTx)
    );

endmodule
