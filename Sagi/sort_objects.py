from operator import attrgetter

class Language:
    def __init__(self, name, lang_id):
        self.name = name
        self.lang_id = lang_id

    def __str__(self) -> str:
        return "{:2d} : {}".format(self.lang_id, self.name)

languages = [
    Language("English", 2),
    Language("French", 44),
    Language("German", 5),
    Language("Japan", 15)
]

for language in languages:
    print(language)

sorted_languages = sorted(languages, key=attrgetter('lang_id'))

print("----------")
for language in sorted_languages:
    print(language)