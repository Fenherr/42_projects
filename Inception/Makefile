COMPOSE		= srcs/docker-compose.yml

all:
	-mkdir /home/ngrenoux/data /home/ngrenoux/data/mysql /home/ngrenoux/data/wordpress
	-cp /home/ngrenoux/Documents/.env ./srcs
	docker compose -f $(COMPOSE) up -d
re: fclean all
down:
	docker compose -f $(COMPOSE) down
fclean: stop down
	-docker rm -f $$(docker ps -a -q)
	-docker volume rm $$(docker volume ls -q)
	-docker system prune --force --all
	-docker volume prune --force
	-docker network prune --force
	-sudo rm -rf ~/data/
stop:
	-docker stop $$(docker ps -qa)
.PHONY: all re nginx prune down fclean wordpress mariadb stop
