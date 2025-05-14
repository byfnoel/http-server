#include <asio.hpp>
#include <iostream>
#include <string>
#include <thread>

// Use the asio library for tcp networking connection
using asio::ip::tcp;

class HTTPServer {
public:
  HTTPServer(short port)
      : acceptor_(io_context_, tcp::endpoint(tcp::v4(), port)) {
    startAccept();
  }

  void run() { io_context_.run(); }

private:
  void startAccept() {
    auto socket = std::make_shared<tcp::socket>(io_context_);
    acceptor_.async_accept(*socket, [this, socket](std::error_code ec) {
      if (!ec) {
        std::thread(&HTTPServer::handleRequest, this, socket).detach();
      }
      startAccept();
    });
  }

  void handleRequest(std::shared_ptr<tcp::socket> socket) {
    try {
      // Read HTTP request from the client socket
      asio::streambuf request;
      asio::read_until(*socket, request, "\r\n");

      // Prepare an HTTP response
      std::string msg = "Successfully connected on port " +
                        std::to_string(socket->local_endpoint().port());
      std::string httpResponse =
          "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(msg.length()) +
          "\r\n\r\n" + msg;

      // Send HTTP response to the client
      asio::write(*socket, asio::buffer(httpResponse));
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }

  asio::io_context io_context_;
  tcp::acceptor acceptor_;
};

int main() {
  try {
    HTTPServer server(8080);
    std::cout << "Listening on port 8080..." << std::endl;
    server.run();
  } catch (std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
