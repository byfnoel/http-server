import java.io.IOException;
import java.net.ServerSocket;
import java.nio.charset.StandardCharsets;

public class HTTPServer {
    public static void main(String[] args) throws Exception {
        final ServerSocket server;
        server = new ServerSocket(8080);
        System.out.println("Listening to port..." + server.getLocalPort() + " at " + server.getLocalSocketAddress());
        while (true) {
            // Read HTTP request from the client socket
            try (var socket = server.accept()) {

                //Prepare an HTTP response
                String msg;
                msg = "Successfully connected on port...";
                String httpResponse;
                httpResponse = "HTTP/1.1 200 OK\r\n\r\n" + msg + server.getLocalPort();

                /* Send HTTP response to the client */
                socket.getOutputStream()
                        .write(httpResponse.getBytes(StandardCharsets.UTF_8));
            }
            // Close the socket
            catch (IOException e) {
                System.out.println("Error on accept socket!");

            }
        }
    }
}
