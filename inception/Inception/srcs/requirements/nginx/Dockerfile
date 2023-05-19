FROM debian:buster

RUN		apt update && apt upgrade -y
RUN		apt install nginx openssl -y

RUN 		mkdir /etc/nginx/ssl

RUN		openssl req -x509 -nodes -days 365 -newkey rsa:4096 \
			-keyout /etc/nginx/ssl/ngrenoux.key \
			-out /etc/nginx/ssl/ngrenoux.crt \
			-sha256 -subj "/C=FR/ST=FRANCE/L=ANGOULEME/O=42 ANGOULEME/OU=/CN=ngrenoux.42.fr/"

COPY		./conf/nginx.conf /etc/nginx/conf.d

RUN		mkdir -p /run/nginx

EXPOSE		443

CMD		["nginx", "-g", "daemon off;"]
