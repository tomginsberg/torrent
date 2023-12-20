#include <iostream>
#include <libtorrent/session.hpp>
#include <libtorrent/magnet_uri.hpp>
#include <libtorrent/torrent_status.hpp>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: torrent magnet_link\n";
        return 1;
    }

    try {
        lt::settings_pack settings;
        settings.set_int(lt::settings_pack::alert_mask, lt::alert::status_notification);

        lt::session session(settings);

        lt::add_torrent_params params;
        params.save_path = "."; 
        params.url = argv[1];

        lt::torrent_handle handle = session.add_torrent(std::move(params));

        std::cout << "Downloading..." << std::endl;
        while (!handle.status().is_seeding) {
            lt::torrent_status status = handle.status();
            std::cout << "\r" << (status.progress * 100) << "% complete (down: "
                      << (status.download_rate / 1000) << " kB/s up: "
                      << (status.upload_rate / 1000) << " kB/s peers: "
                      << status.num_peers << ") " << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        std::cout << "\nDownload completed" << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

