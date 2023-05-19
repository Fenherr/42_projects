FROM debian:buster

RUN		apt-get update -y
RUN		apt-get install -y \
		wget \
		curl \
		bash \
		php \
		php-cgi \
		php-fpm \
		php-mysql \
		php-pdo \
		php-gd \
		php-cli \
		php-mbstring \
		&& rm -rf /var/lib/apt/lists/*

RUN		curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN		chmod +x wp-cli.phar
RUN		mv wp-cli.phar /usr/local/bin/wp

COPY		./conf/www.conf /etc/php/7.3/fpm/pool.d

RUN		mkdir /run/php

COPY		./tools/create_wordpress.sh /usr/local/bin
RUN		chmod +x /usr/local/bin/create_wordpress.sh
ENTRYPOINT	["/usr/local/bin/create_wordpress.sh"]

WORKDIR		/var/www/html/

EXPOSE		9000

CMD		["/usr/sbin/php-fpm7.3", "-F"]
