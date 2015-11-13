
class Song
    @@plays = 0
    attr_writer :name, :artist, :duration
    def initialize(name, artist, duration)
        @name     = name
        @artist   = artist
        @duration = duration
        @plays    = 0
    end
    def to_s
        "Song: #@name--#@artist(#@duration)"
    end

    def name
        @name
    end

    def artist
        @artist
    end

    def duration
        @duration
    end

    def duration=(new_duration)
        @duration = new_duration
    end

    def play
        @plays  += 1
        @@plays += 1
        puts "This song: #@plays plays. Total #@@plays plays."
    end
end

class SongList
    MAX_TIME = 5*60
    def initialize
        @songs = Array.new
    end

    def self.is_too_long(song)
        return song.duration > MAX_TIME
    end

    def append(song)
        @songs.push(song)
    end

    def delete_first
        @songs.shift
    end

    def delete_last
        @songs.pop
    end

    def [](index)
        @songs[index]
    end
end

song1 = Song.new("Bicyclops", "Fleck", 260)
puts SongList.is_too_long(song1)
song2 = Song.new("The Calling", "Santana", 468)
puts SongList.is_too_long(song2)
