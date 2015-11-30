
class Song
    @@plays = 0
    attr_accessor :name, :artist, :duration
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

class WordIndex
    def initialize
        @index = {}
    end

    def add_to_index(obj, *phrases)
        phrases.each do |phrase|
            phrase.scan(/\w[-\w']+/) do |word|
                word.downcase!
                @index[word] = [] if @index[word].nil?
                @index[word].push(obj)
            end
        end
    end

    def lookup(word)
        @index[word.downcase]
    end
end

class SongList
    MAX_TIME = 5*60
    def initialize
        @songs = Array.new
        @index = WordIndex.new
    end

    def self.is_too_long(song)
        return song.duration > MAX_TIME
    end

    def append(song)
        @songs.push(song)
        @index.add_to_index(song, song.name, song.artist)
        self
    end

    def lookup(word)
        @index.lookup(word)
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

    def with_title_old(title)
        for i in 0...@songs.length
            return @songs[i] if title == @songs[i].name
        end
        return nil
    end

    def with_title(title)
        @songs.find {|song| title == song.name}
    end
end

song1 = Song.new("Bicyclops", "Fleck", 260)
puts SongList.is_too_long(song1)
song2 = Song.new("The Calling", "Santana", 468)
puts SongList.is_too_long(song2)

list = SongList.new
s1 = Song.new("title1", "artist1", 1)
s2 = Song.new("title2", "artist2", 2)
s3 = Song.new("title3", "artist3", 3)
s4 = Song.new("title4", "artist4", 4)
list.append(s1).append(s2).append(s3).append(s4)
#puts list.with_title("title1")

File.open("./songdata") do |song_file|
    song_lists = SongList.new
    song_file.each do |line|
        file, length, name, title = line.chomp.split(/\s*\|\s*/)
        name.squeeze!(" ")
        mins, secs = length.scan(/\d+/)
        song_lists.append(Song.new(title, name, mins.to_i*60+secs.to_i))
    end
    puts song_lists.lookup("Fats")
    puts song_lists.lookup("ain't")
    puts song_lists.lookup("RED")
    puts song_lists.lookup("WoRlD")
end

class VU
    #include Comparable
    attr_accessor :volume
    def initialize(volume) # 0..9
        @volume = volume
    end

    def inspect
        "#" * @volume
    end

    #Support for ranges
    def <=>(other)
        self.volume <=> other.volume
    end

    def succ
        raise(IndexError, "Volume too big") if @volume >= 9
        VU.new(@volume.succ)
    end
end

#test_volume = VU.new(3)
#puts test_volume.to_a

medium_volume = VU.new(4)..VU.new(8)
print medium_volume.to_a
puts
puts medium_volume
#medium_volue.find {|medium| puts medium}
puts medium_volume.include?(VU.new(10))


=begin
require 'test/unit'
class TestSongList < Test::Unit::TestCase
    def test_delete
        list = SongList.new
        s1 = Song.new("title1", "artist1", 1)
        s2 = Song.new("title2", "artist2", 2)
        s3 = Song.new("title3", "artist3", 3)
        s4 = Song.new("title4", "artist4", 4)
        list.append(s1).append(s2).append(s3).append(s4)
        assert_equal(s1, list[0])
        assert_equal(s3, list[2])
        assert_nil(list[9])
        assert_equal(s1, list.delete_first)
        assert_equal(s2, list.delete_first)
        assert_equal(s4, list.delete_last)
        assert_equal(s3, list.delete_last)
        assert_nil(list.delete_last)
    end
end
=end
