## Cloudflare WARP
systemctl enable --now warp-svc
warp-cli register
warp-cli connect
warp-cli status
warp-cli warp-dns-stats


## DNS and WARP
Add
nameserver 1.1.1.1 to /etc/resolv.conf;
DNS=1.1.1.1, ResolveUnicastSingleLabel=yes to /etc/systemd/resolved.conf;
