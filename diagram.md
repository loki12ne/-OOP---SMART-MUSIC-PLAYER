```mermaid
classDiagram
    class Observer {
        <<interface>>
        +update(state: string): void
    }

    class Subject {
        -observers: vector<shared_ptr<Observer>>
        +attach(observer: shared_ptr<Observer>): void
        +detach(observer: shared_ptr<Observer>): void
        +notify(state: string): void
    }

    class Song {
        -title: string
        +Song(title: string)
        +getTitle(): string
    }

    class Playlist {
        -songs: vector<Song>
        +addSong(song: Song): void
        +getIterator(): Iterator
    }

    class Iterator {
        -current: iterator
        -end: iterator
        +Iterator(start: iterator, end: iterator)
        +hasNext(): bool
        +next(): Song
    }

    class AudioPlayerImplementation {
        <<interface>>
        +playAudio(audio: string): void
    }

    class SimpleAudioPlayer {
        +playAudio(audio: string): void
    }

    class AudioPlayerAbstraction {
        #implementation: shared_ptr<AudioPlayerImplementation>
        +AudioPlayerAbstraction(impl: shared_ptr<AudioPlayerImplementation>)
        +play(audio: string): void
    }

    class SmartAudioPlayer {
        +play(audio: string): void
    }

    class SmartMusicPlayer {
        -playlist: Playlist
        -audioPlayer: shared_ptr<AudioPlayerAbstraction>
        -currentState: string
        +SmartMusicPlayer(player: shared_ptr<AudioPlayerAbstraction>)
        +addSong(song: Song): void
        +play(): void
        +pause(): void
        +stop(): void
    }

    class ConsoleLogger {
        +update(state: string): void
    }

    Observer <|.. ConsoleLogger
    Subject <|-- SmartMusicPlayer
    AudioPlayerImplementation <|.. SimpleAudioPlayer
    AudioPlayerAbstraction <|-- SmartAudioPlayer

    SmartMusicPlayer --> Playlist
    SmartMusicPlayer --> AudioPlayerAbstraction
    Playlist --> Iterator
    SmartMusicPlayer o--> ConsoleLogger
