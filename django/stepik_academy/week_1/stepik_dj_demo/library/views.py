from django.http import HttpResponseNotFound
from django.shortcuts import render
from django.views.generic import ListView

from library.models import Author


class MainAuthorListView(ListView):
    template_name = 'main.html'
    model = Author


def author_detail_view(request, id):
    context = {}

    author = Author.objects.filter(id=id).first()
    if not author:
        return HttpResponseNotFound(f"Нет автора с id {id}")

    context["author"] = author
    return render(request, "author/detail.html", context)
