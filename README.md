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
