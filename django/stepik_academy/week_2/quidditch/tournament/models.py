from django.db import models


class Team(models.Model):
    name = models.CharField(max_length=64)

    class Meta:
        app_label = 'tournament'


class Player(models.Model):
    height = models.FloatField()
    name = models.CharField(max_length=64)
    team = models.ForeignKey(Team, on_delete=models.CASCADE)


class Game(models.Model):
    home_team = models.ForeignKey(Team, related_name='game_at_home', on_delete=models.CASCADE)
    home_team_points = models.IntegerField()
    rival_team = models.ForeignKey(Team, related_name='rival_game', on_delete=models.CASCADE)
    rival_team_points = models.IntegerField()
    date = models.DateField()


class League(models.Model):
    name = models.CharField(max_length=32)
    champion = models.ForeignKey(Team, related_name='champion_of', on_delete=models.CASCADE)
    number_of_teams = models.IntegerField()

    class Meta:
        app_label = 'tournament'


class Coach(models.Model):
    name = models.CharField(max_length=48)
    experience = models.IntegerField()
    team = models.ForeignKey(Team, on_delete=models.CASCADE)

    class Meta:
        app_label = 'tournament'
