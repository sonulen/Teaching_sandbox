from django.db import models
from django.urls import reverse


class Genre(models.Model):
    name = models.CharField(max_length=30, verbose_name='название жанра')

    class Meta:
        verbose_name = 'жанр'
        verbose_name_plural = 'жанры'

    def __str__(self) -> str:
        return f'жанр {self.name}'


class Author(models.Model):
    first_name = models.CharField(max_length=30, verbose_name='имя')
    last_name = models.CharField(max_length=30, verbose_name='фамилия')
    birth_date = models.DateField(verbose_name='дата рождения')
    city = models.CharField(max_length=30, verbose_name='город')

    class Meta:
        verbose_name = 'автор'
        verbose_name_plural = 'авторы'

    def __str__(self) -> str:
        return f'{self.first_name} {self.last_name}'

    def get_absolute_url(self):
        return reverse('author_detail', args=[str(self.pk)])


class Book(models.Model):
    title = models.CharField(max_length=100, verbose_name='заголовок')
    authors = models.ManyToManyField(Author, verbose_name='авторы', related_name='author_books')
    genres = models.ManyToManyField(Genre, verbose_name='жанры', related_name='genre_books')
    publish_date = models.DateField(verbose_name='дата публикации')

    class Meta:
        verbose_name = 'книга'
        verbose_name_plural = 'книги'

    def __str__(self) -> str:
        return f'{self.title} ({self.publish_date})'
