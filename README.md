# zephyr-boards

Додайте до вашого `west.yml' в розділи `remotes` та `projects`:

```
manifest:
  remotes:
    - name: FenixUkraine
      url-base: https://github.com/FenixUkraine
  projects:
    - name: zephyr-boards
      remote: FenixUkraine
      revision: main
      clone-depth: 1
      path: deps/zephyr-boards
```


## Внесок у проєкт

Ми вітаємо ваш внесок! Будь ласка, дотримуйтеся наступних кроків:

1. Зробіть форк цього репозиторію.
2. Створіть нову гілку (`git checkout -b feature-branch`).
3. Внесіть зміни та закомітьте їх (`git commit -am 'Додано нову функцію'`).
4. Відправте зміни у форк (`git push origin feature-branch`).
5. Створіть Pull Request.

## Інструкції та поради щодо роботи з репозиторіями компонентів

Проєкт має модульну архітектуру. Зміни зазвичай вносяться в модулі, а не в основний проєкт. Нижче наведено нагадування щодо зручної роботи з субмодулями.

Прості зміни можна вносити у відповідних репозиторіях модулів, відправляти зміни, а потім в основному проєкті виконувати:

```shell
west update -o=--depth=1 -n
```

Під час активного налагодження зручніше вносити правки в локальних копіях модулів. Механізми `west` імпортують модулі в режимі `detached HEAD`. Щоб відправити зміни в модулі, виконайте:

- Перейдіть до каталогу з модулем або відкрийте його в десктопному Git-клієнті.
- Створіть нову гілку.
- Закомітьте зміни.
- Відправте гілку.
- Створіть pull request на GitHub.
- Прийміть pull request на GitHub.
- Оновіть проєкт через `west`.

```shell
cd modules/shock-sensor-driver
git status
git checkout -b feature/my-changes-1
git add .
git commit -m "Опис змін."
git push -u baden feature/my-changes-1
```

Перед створенням коміту оновіть локальний стан гілки `main` і усуньте конфлікти:

```shell
cd modules/shock-sensor-driver
git status
git checkout -b feature/my-changes-1
git add .
git commit -m "Опис змін."
git checkout main
git pull origin main
git checkout feature/my-changes-1
git rebase main
```

Вирішення конфліктів:

```shell
git status  # Показує файли з конфліктами (позначені червоним)
```

Приклад конфлікту у файлі:

```diff
<<<<<<< HEAD
// Зміни з main
public void calculate() {
    int x = 10;
}
=======
// Ваші зміни з feature/login
public void calculate() {
    int x = 20;
}
>>>>>>> 1234567... Commit message
```

Виправте конфлікт. Плагін у VSCode або десктопний клієнт Git спрощують це.

- Позначте файл як вирішений.
- Продовжуйте rebase.

```shell
git add <file>
git rebase --continue
```

Або, якщо файл потрібно видалити:

```shell
git rm <file>
git rebase --continue
```

Після вирішення конфліктів відправте коміт. Він буде від актуальної гілки `main`.

```shell
git push -u baden feature/my-changes-1
```

Спробуйте `git rebase -i main` в інтерактивному режимі. Можливо, у вашій десктопній версії Git є зручний механізм для rebase.
