
template<typename T, typename... Args>
T* EntityManagerCreateEntity(Args&&... args)
{
    auto entity = std::make_unique<T>(nextID, std::forward<Args>(args)...);

    T* rawPtr = entity.get();

    entities[nextID] = std::move(entity);
    ++nextID;

    return rawPtr;
}
