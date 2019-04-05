use std::net::TcpListener;
use std::net::TcpStream;
use std::net::SocketAddr;
use std::process;
use std::io::Read;
use std::str;

fn main()
{
    match TcpListener::bind("127.0.0.1:8080")
    {
        Ok(l) => listen_server(l),
        Err(m) =>
        {
            println!("{}", m);
            process::exit(1);
        },
    }
}

fn listen_server(l: TcpListener)
{
    println!("Listening on port 8080");

    loop
    {
        let (socket, addr) = l.accept().unwrap();
        handle_client(socket, addr);
    }
}

fn handle_client(mut s: TcpStream, a: SocketAddr)
{
    println!("adddress {}", a.ip());
    println!("port {}", a.port());

    let mut tmp_buf = [0; 100];
    let mut buf = Vec::new();
    let mut read_on = true;
    let mut offset: usize = 0;
    let mut last_three = ['\0'; 3];

    while read_on
    {
        let nread = match s.read(&mut tmp_buf)
        {
            Ok(size) => size,
            Err(m) =>
            {
                println!("what?! {}", m);
                process::exit(1);
            },
        };

        buf.extend_from_slice(&tmp_buf[0..nread]);

        for i in offset..buf.len()
        {
            // look for \r\n\r\n
            if last_three[0] == '\r' && last_three[1] == '\n'
                && last_three[2] == '\r' && buf[i] as char == '\n'
            {
                read_on = false;
                break;
            }

            last_three[0] = last_three[1];
            last_three[1] = last_three[2];
            last_three[2] = buf[i] as char;
        }

        offset += nread;
    }

    let readable = match str::from_utf8(&buf) {
        Ok(v) => v,
        Err(e) => panic!("Invalid UTF-8 sequence: {}", e),
    };

    println!("read {}", offset);
    println!("data {}", readable);
}
