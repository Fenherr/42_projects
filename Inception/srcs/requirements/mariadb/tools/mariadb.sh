#!/bin/sh

mysql_install_db

/etc/init.d/mysql start

if [-d "/var/lib/mysql/$MYSQL_DATABASE"]
then
	echo "Database already exist"
else
	
mysql_secure_installation << EOF

Y
1234
1234
Y
n
Y
Y
EOF

echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;" | mysql -uroot

echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE; GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; FLUSH PRIVILEGES" | mysql -uroot

mysql -uroot -p$MYSQL_ROOT_PASSWORD $MYSQL_DATABASE < /usr/local/bin/wordpress.sql

fi

/etc/init.d/mysql stop

exec "$@"
