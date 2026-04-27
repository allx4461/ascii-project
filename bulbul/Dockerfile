
FROM ubuntu:24.04 AS builder
RUN apt-get update && apt-get install -y g++ cmake make
WORKDIR /app
COPY . .

RUN g++ -std=c++17 src/*.cpp -o aquarium_app -pthread


FROM ubuntu:24.04
RUN apt-get update && apt-get install -y libstdc++6 && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY --from=builder /app/aquarium_app .


EXPOSE 8080
CMD ["./aquarium_app"]