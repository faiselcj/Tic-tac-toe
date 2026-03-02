# Use lightweight GCC image
FROM gcc:11

# Set working directory
WORKDIR /app

# Copy source code
COPY main.cpp .

# Compile the application
RUN g++ -std=c++17 main.cpp -o tic_tac_toe

# Run the app
CMD ["./tic_tac_toe"]
