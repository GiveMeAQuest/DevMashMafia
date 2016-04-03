#API сокетов


- [Вход в комнату](#join-room)
- [Создание комнаты](#create-room)
- [Получение списка игроков в комнате (до начала игры)](#get-waiting-players)
- [Выход из комнаты](#leave-room)
- [Получение данных о комнате](#get-room)
- [Любая ошибка](#err)
- [В комнату игрока зашёл другой игрок](#player-joined)
- [Из комнаты игрока вышел другой игрок](#player-left)
- [Из комнаты игрока вышел хост и сервер назначил нового хоста](#host-changed)


##Условные обозначения
`{a, b, c, ...}` - JSON-объект с полями "a", "b", "c", ...

`[a]` - массив JSON-объектов "а"

Все названия полей, а также строковые значения надо заключать в двойные кавычки!

##События

###События, отправляемые пользователем серверу


<a name='join-room'></a>
####Вход в комнату
- `event`: "join room"
- `data`: {nickname, room\_id}
  - `nickname`: ник игрока (строка)
  - `room_id`: ID комнаты (число)

__Ответ сервера__
- `event`: "room joined"
- `data`: room_id
  - `room_id`: ID комнаты, в которую зашёл игрок (число)

---

<a name='create-room'></a>
####Создание комнаты
- `event`: "create room"
- `data`: {players}
  - `players`: Необходимое кол-во игроков в комнате (число)
 
__Ответ сервера__
- `event`: "room created"
- `data`: room_id
  - `room_id`: ID созданной комнаты (число)
 
---

<a name='get-waiting-players'></a>
####Получение списка игроков в комнате (до начала игры)
- `event`: "get waiting players"
- `data`: -

__Ответ сервера__
- `event`: "players"
- `data`: [player]
  - `player`: {id, nickname}
    1. `id`: ID игрока (число)
    2. `nickname`: Ник игрока (строка)

---

<a name='leave-room'></a>
####Выход из комнаты
- `event`: "leave room"
- `data`: -

__Ответ сервера__
- `event`: "room left"
- `data`: -

---

<a name='get-room'></a>
####Получение данных о комнате
- `event`: "get room"
- `data`: room\_id
  - `room_id`: ID нужной комнаты (число)
 
__Ответ сервера__
- `event`: "room"
- `data`: {id, host_id, phase}
  - `id`: ID комнаты (число)
  - `host_id`: ID хоста комнаты (число)
  - `phase`: Название текущей фазы комнаты (строка)


###События, отправляемые сервером пользователю


<a name='err'></a>
####Любая ошибка
- `event`: "err"
- `data`: error
  - `error`: Текст ошибки (строка)
 
---

<a name='player-joined'></a>
####В комнату игрока зашёл другой игрок
- `event`: "player joined"
- `data`: {id, nickname, room_id}
  - `id`: ID зашедшего игрока (число)
  - `nickname`: Ник зашедшего игрока (строка)
  - `room_id`: ID комнаты, в которую зашёл игрок (число)

---

<a name='player-left'></a>
####Из комнаты игрока вышел другой игрок
- `event`: "player left"
- `data`: id
  - `id`: ID вышедшего игрока (число)

---

<a name='host-changed'></a>
####Из комнаты игрока вышел хост и сервер назначил нового хоста
- `event`: "host changed"
- `data`: host\_id
  - `host_id`: ID игрока, ставшего хостом (число)
